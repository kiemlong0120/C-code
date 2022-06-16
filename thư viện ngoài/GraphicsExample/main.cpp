#include "graphics.h"

int main( )
{
	//Khởi tạo cửa số window có kích thước (400,300)
    initwindow(400, 300, "First Sample");
	//		 0,0 _ _ _ _ width,0
	//			|	    |
	//			|	    |
	//0,height	|_ _ _ _| width,height
	
	//Hàm vẽ 1 đường thằng từ điểm (0,0) -> (10,10)
	setcolor(YELLOW);
	line(0,0,50,50);

	//Hàm vẽ 1 điểm với kích thước là 10 pixel, tại tọa độ (100,100) có màu trắng
	setcolor(WHITE);
	fillellipse(100,100,10,10);

    while (!kbhit( ))
    {
        delay(200);
    }
    return 0;
}