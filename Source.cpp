#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <zbar.h>  
#include <iostream>  
#include <tserial.h>
#include <bot_control.h>

int n = 1;
char j = 'r';
using namespace std;
using namespace zbar;

long position1 [20] ;
char arrpos[20];
char arr[100000];
int i = 1;
int m = 0;

using namespace cv;
//g++ main.cpp /usr/local/include/ /usr/local/lib/ -lopencv_highgui.2.4.8 -lopencv_core.2.4.8  

serial comm;

//comm.startDevice("COM4", 9600);
	
bool check(IplImage* img)
{
	m = 0;
	for (int y = 0; y < img->height; y++)
	{
		uchar* ptr = (uchar*)(img->imageData + y * img->widthStep);
		for (int x = 0; x < img->width; x++)
		{
			if ((ptr[3 * x] <145) && (ptr[3 * x + 1]>190) && (ptr[3 * x + 2] >190))
				m++;// enter yellows grb code here.. just for testing
		}
	}


	if (m > 10)
	{
		cout << "YFOUND " << endl;
		return true;
		
	}
	else
	{
		cout << "YNOTFOUND" << endl;
		return false;
	}
}
char display()
{
	char opt;
	cout << "Welcome to library book finder program";
		cout << endl;
		cout << "chose the book you want";
		cout << endl;
		cout << "A. BRITISH PHILOSOPHY";
		cout << endl;
		cout << "B. KEER KEGAN";
		cout << endl;
		cout << "C. psychology etc";
		cout << endl;
		cout << "D";
		cout << endl;
		cout << "E";
		cout << endl;
		cout << "F";
		cout << endl;
		cout << "G";
		cout << endl;
		cout << "H";
		cout << endl;
		cout << "I";
		cout << endl;
		cout << "J";
		cout << endl;
		cout << "K";
		cout << endl;
		cout << "L";
		cout << endl;
		cout << "M";
		cout << endl;
		cout << "N";
		cout << endl;
		cout << "O";
		cout << endl;
		cout << "P";
		cout << endl;
		cout << "Q";
		cout << endl;
		cout << "R";
		cout << endl;
		cout << "S";
		cout << endl;
		cout << "T";
		cout << endl;
		cout << endl;
		cin >> opt;
		int a = 'a';
		if (opt > a)
			opt = opt - a + 65;
		return opt;





}
long catalog(char bookopt)
{
	if (bookopt == 'A')
		return 199601305;
	if (bookopt == 'B')
		return 199549028;//enter barcodes
	// repeat for other choices
	if (bookopt == 'C')
		return 199534640;
}

int resetingarduino(long num2)
{
	
	comm.send_data('R');
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);

	CvCapture* capture = cvCreateCameraCapture(1);
	IplImage* frame1 = cvQueryFrame(capture);
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);

	CvCapture* capture2 = cvCreateCameraCapture(1);
	IplImage* frame2 = cvQueryFrame(capture2);
	
	for (int p = 0; p <20; p++)
	{
		position1[p] = 0;
	}
	VideoCapture cap (1); // open the video camera no. 0  
	// cap.set(CV_CAP_PROP_FRAME_WIDTH,800);  
	// cap.set(CV_CAP_PROP_FRAME_HEIGHT,640);  
	if (!cap.isOpened()) // if not success, exit program  
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video  
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video  
	cout << "Frame size : " << dWidth << " x " << dHeight << endl;
	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo" 
	
	comm.send_data('R');

	while (1)
	{
		int ctr5 = 0;
		arr[0] = 's';
		CvCapture* capture = cvCreateCameraCapture(1);
		IplImage* frame1 = cvQueryFrame(capture);
		int ctr = 1;
		j = 'r';
		cvShowImage("Example2", frame1);
		if (check(frame1)&&(j=='r'))
		{
			j = 's'; // to send a signal to arduino to stop...
		}
		else
			j = 'r';
		arr[n] = j;
		if (j == 's')
			if (arr[n - 1] == 's')
				j = 'r';
		n++;

		
		comm.send_data(j);
	
		Mat frame;
		bool bSuccess = cap.read(frame); // read a new frame from video  
		if (!bSuccess) //if not success, break loop  
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat grey;
		cvtColor(frame, grey, CV_BGR2GRAY);
		int width = frame.cols;
		int height = frame.rows;
		uchar *raw = (uchar *)grey.data;
		// wrap image data   
		Image image(width, height, "Y800", raw, width * height);
		// scan the image for barcodes   
		int n = scanner.scan(image);
		// extract results   
		for (Image::SymbolIterator symbol = image.symbol_begin();
			symbol != image.symbol_end();
			++symbol) {
			vector<Point> vp;
			// do something useful with results   
			long j1 = atol(symbol->get_data().c_str());
			if (j1 > 0)
		
			cout << j1;			
			int n = symbol->get_location_size();
			if ((position1[i - 1] != j1) && (symbol->get_type_name()=="ISBN-10"))
			{
				position1[i] = j1;
				
				comm.send_data('m');
				
				i++;
			}
		//
			

			for (int i = 0; i<n; i++){
				vp.push_back(Point(symbol->get_location_x(i), symbol->get_location_y(i)));
			}
			RotatedRect r = minAreaRect(vp);
			Point2f pts[4];
			r.points(pts);
			for (int i = 0; i<4; i++){
				line(frame, pts[i], pts[(i + 1) % 4], Scalar(255, 0, 0), 3);
			}
			//cout<<"Angle: "<<r.angle<<endl;   
		}
		imshow("MyVideo", frame); //show the frame in "MyVideo" window  
		if (position1[i - 1] == num2)
		{
			comm.send_data('x');
			break;
		}
	/*	if (i == 3)
		{
			while (1)
			{
				CvCapture* capture1 = cvCreateCameraCapture(1);
				IplImage* frame2 = cvQueryFrame(capture1);
				if (ctr5 < 1)
					comm.send_data('w');
				else
					comm.send_data('g');

				if (check(frame2))

				{
					comm.send_data('z');
					break;
				}
				ctr5++;

			}

		}*/
		
		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop  
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
		
			
	}
	return 0;
}
int settingarduino(char bookwant)
{
	comm.send_data('S');
	for (int j = 0; j < i; j++)
	{
		if (arrpos[j] == bookwant)
		{
			char ctr = 65 + j;
			comm.send_data(ctr);
		}
	}return 0;

}
int main()
{

	comm.startDevice("COM4", 9600);
	char condt;
	char bookiwant = display();
	cout << endl;
	cout << "please press R to search your book";
	cin >> condt;
	long barnum = catalog(bookiwant);
	if (condt = 'R')
	{
		comm.send_data('R');
		resetingarduino(barnum);
	}
	cout << "do you want to search the book..?? Y OR N";
	cin >> condt;
	if (condt = 'Y')
		settingarduino(bookiwant);
		return 0;
}












