
/*
 * CSE/ENGR 142 GP142_Demo
 *
 * 1/25/95
 * Author(s):         Larry Ruzzo
 * Email Address(s):  ruzzo@cs.washington.edu
 *
 * This program is a demo of some of the features of
 * GP142 --- the CSE/ENGR 142 Graphics Package.
 * It includes simple drawing commands, keyboard and mouse
 * interaction, and a simple animation.
 *
 * Revision history:
 * 11/18/97 Dan Boren  - Removed calls to obsolete function GP142_undo()
 *
 */

#include <vector>
#include <stdio.h>
//#include "GP142.C"
#include <math.h>
#include <Windows.h>
#pragma once
#include "Shape.h"
#include"OpenShape.h"
#include "circle.h"
#include"line.h"
#include"polygon.h"
#include"rectangle.h"
#include"curve.h"
#include"text.h"





#define PI 3.1415926535
#define ANIMATE_MSG "Select \"Animate\"\nOn the \"Run\" Menu"
#define TEXT_SIZE 20





 //You will use the following 5 functions do to all work

 //A) DRAWING FUNCTIONS
 //the two drawing functions that you will use to make all shapes
void draw_line(int x1, int y1, int x2, int y2, int color = WHITE, int width = 1) {
	GP142_lineXY(color, x1, y1, x2, y2, width);
}

void draw_circle(int x, int y, int radius, int color = WHITE) {
	GP142_circleXY(color, x, y, radius);
}

//B) EVENT HANDLERS
//Mouse handler
void handle_mouse(int x, int y) {
	GP142_printfXY(YELLOW, x, y, 9, "Mouse at (%d,%d)", x, y);
}

//Keyboard handler
void handle_kbd(char c)
{
	//put the character anywhere you want to.
	//I'm putting it on the origin
	GP142_printfXY(WHITE, 0, 0, TEXT_SIZE, "%c", c);
}

//periodic handler you will not need to use because we're not doing animation
void demo_handle_periodic(void) {};


/******************************************************************************
 *
 * The Main Program
 * ----------------
 *
 * The main program takes care of initialization and cleanup, and the high-level
 * control of all actions in the program, but most of the detail work is
 * relegated to sub-functions, so that the structure of main stays clear and
 * simple.
 *
 */


void Draw_Panel()
{
	GP142_lineXY(9, -475, 400, -425, 400, 3);
	GP142_lineXY(9, -475, 350, -425, 350, 3);
	GP142_lineXY(9, -475, 400, -475, 350, 3);
	GP142_lineXY(9, -425, 400, -425, 350, 3);
	GP142_lineXY(8, -440, 380, -460, 360, 3);
	//dotted
	GP142_lineXY(9, -415, 400, -365, 400, 3);
	GP142_lineXY(9, -415, 350, -365, 350, 3);
	GP142_lineXY(9, -415, 400, -415, 350, 3);
	GP142_lineXY(9, -365, 400, -365, 350, 3);

	GP142_lineXY(9, -475, 340, -425, 340, 3);
	GP142_lineXY(9, -475, 290, -425, 290, 3);
	GP142_lineXY(9, -475, 340, -475, 290, 3);
	GP142_lineXY(9, -425, 340, -425, 290, 3);
	//inside circle 
	GP142_circleXY(8, -450, 315, 15);
	GP142_circleXY(0, -450, 315, 10);

	GP142_lineXY(9, -475, 280, -425, 280, 3);
	GP142_lineXY(9, -475, 230, -425, 230, 3);
	GP142_lineXY(9, -475, 280, -475, 230, 3);
	GP142_lineXY(9, -425, 280, -425, 230, 3);
	//inside rectangle
	GP142_lineXY(8, -470, 270, -450, 270, 3);
	GP142_lineXY(8, -470, 260, -450, 260, 3);
	GP142_lineXY(8, -470, 270, -470, 260, 3);
	GP142_lineXY(8, -450, 270, -450, 260, 3);

	GP142_lineXY(9, -475, 220, -425, 220, 3);
	GP142_lineXY(9, -475, 170, -425, 170, 3);
	GP142_lineXY(9, -475, 220, -475, 170, 3);
	GP142_lineXY(9, -425, 220, -425, 170, 3);
	//inside triangle
	GP142_textXY(8, -470, 180, 15, "curve");


	GP142_lineXY(9, -475, 160, -425, 160, 3);
	GP142_lineXY(9, -475, 110, -425, 110, 3);
	GP142_lineXY(9, -475, 160, -475, 110, 3);
	GP142_lineXY(9, -425, 160, -425, 110, 3);
	//inside polygon
	GP142_textXY(8, -470, 130, 15, "polygon");


	GP142_lineXY(9, -475, 100, -425, 100, 3);
	GP142_lineXY(9, -475, 50, -425, 50, 3);
	GP142_lineXY(9, -475, 100, -475, 50, 3);
	GP142_lineXY(9, -425, 100, -425, 50, 3);
	//inside eraser
	GP142_textXY(8, -470, 75, 15, "eraser");

	GP142_lineXY(9, -475, 40, -425, 40, 3);
	GP142_lineXY(9, -475, -10, -425, -10, 3);
	GP142_lineXY(9, -475, 40, -475, -10, 3);
	GP142_lineXY(9, -425, 40, -425, -10, 3);
	////inside bucket
	GP142_textXY(8, -470, 13, 15, "bucket");

	GP142_lineXY(9, -475, -20, -425, -20, 3);
	GP142_lineXY(9, -475, -70, -425, -70, 3);
	GP142_lineXY(9, -475, -20, -475, -70, 3);
	GP142_lineXY(9, -425, -20, -425, -70, 3);
	////inside save
	GP142_textXY(8, -470, -50, 15, "save");

	GP142_lineXY(9, -475, -80, -425, -80, 3);
	GP142_lineXY(9, -475, -130, -425, -130, 3);
	GP142_lineXY(9, -475, -80, -475, -130, 3);
	GP142_lineXY(9, -425, -80, -425, -130, 3);
	//inside dotted Line

	//red color
	GP142_lineXY(9, -480, -160, -450, -160, 3);
	GP142_lineXY(9, -480, -190, -450, -190, 3);
	GP142_lineXY(9, -480, -160, -480, -190, 3);
	GP142_lineXY(9, -450, -160, -450, -190, 3);

	// green
	GP142_lineXY(9, -440, -160, -410, -160, 3);
	GP142_lineXY(9, -440, -190, -410, -190, 3);
	GP142_lineXY(9, -440, -160, -440, -190, 3);
	GP142_lineXY(9, -410, -160, -410, -190, 3);

	//yelow
	GP142_lineXY(9, -440, -230, -410, -230, 3);
	GP142_lineXY(9, -440, -200, -410, -200, 3);
	GP142_lineXY(9, -440, -230, -440, -200, 3);
	GP142_lineXY(9, -410, -230, -410, -200, 3); \
		// blue
		GP142_lineXY(9, -480, -200, -450, -200, 3);
	GP142_lineXY(9, -480, -230, -450, -230, 3);
	GP142_lineXY(9, -480, -200, -480, -230, 3);
	GP142_lineXY(9, -450, -200, -450, -230, 3);
	//orange
	GP142_lineXY(9, -480, -240, -450, -240, 3);
	GP142_lineXY(9, -450, -270, -450, -240, 3);
	GP142_lineXY(9, -480, -240, -480, -270, 3);
	GP142_lineXY(9, -480, -270, -450, -270, 3);
	//white
	GP142_lineXY(9, -440, -240, -410, -240, 3);
	GP142_lineXY(9, -410, -270, -410, -240, 3);
	GP142_lineXY(9, -440, -240, -440, -270, 3);
	GP142_lineXY(9, -440, -270, -410, -270, 3);
	//black
	GP142_lineXY(9, -460, -280, -430, -280, 3);
	GP142_lineXY(9, -460, -310, -430, -310, 3);
	GP142_lineXY(9, -460, -280, -460, -310, 3);
	GP142_lineXY(9, -430, -280, -430, -310, 3);


}
int color_detect(int mouse_x, int mouse_y)
{
	if (mouse_x > -480 && mouse_x < -450 && mouse_y < -160 && mouse_y>-190)
	{
		return  2;
	}
	if (mouse_x > -440 && mouse_x < -410 && mouse_y <-160 && mouse_y>-190)
	{
		return  3;
	}
	if (mouse_x > -480 && mouse_x < -450 && mouse_y < -200 && mouse_y>-230)
	{
		return  9;
	}
	if (mouse_x > -440 && mouse_x < -410 && mouse_y <-200 && mouse_y>-230)
	{
		return  5;
	}
	if (mouse_x > -480 && mouse_x < -450 && mouse_y <-240 && mouse_y> -270)
	{
		return  18;
	}
	if (mouse_x > -440 && mouse_x < -410 && mouse_y < -240 && mouse_y> -270)
	{
		return  1;
	}
	if (mouse_x > -460 && mouse_x < -430 && mouse_y < -280 && mouse_y> -310)
	{
		return  0;
	}
	else
		return 1;
}

int main(void)
{
	//std::vector<int> abc(5);
	int quit = 0;           /* has user signaled quit yet?                      */
	int mouse_x, mouse_y;
	char key_pressed;
	GP142_open();   /* Open and initialize the GP142 Graphics Window    */


	vector<Point> cordinates;
	vector<Point> line_p;
	vector<Point> rec_p;
	vector<Point> poly_p;
	vector<Point> curve_p;
	vector<Shape*>allshapes;
	vector<char>texting;
	vector<Point>p_text;
	int col;
	bool lineClicked=false, style;
	//*********************PANEL**************** 
	Draw_Panel();
	//GP142_pixelXY(17, 0, 0);
	
	
	
	while (!quit) {

		switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed))
		{
		case GP142_QUIT:
			quit = 1;   /* set flag to terminate loop                */
			break;

		case GP142_MOUSE:

		//	if (mouse_x > -475 && mouse_x < -425 && mouse_y < 340 && mouse_y>290)
		//	{
		//		switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) {
		//		case GP142_MOUSE:
		//			col = color_detect(mouse_x, mouse_y);
		//		}

		//		while (cordinates.size() != 2)
		//		{
		//			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed))
		//			{
		//			case GP142_MOUSE:

		//				Point cod;
		//				cod.x = mouse_x;
		//				cod.y = mouse_y;
		//				cordinates.push_back(cod);
		//				if (cordinates.size() == 2)
		//				{
		//					double d = pow((cordinates[0].x) - (cordinates[1].x), 2) + pow((cordinates[0].y) - (cordinates[1].y), 2);
		//					double r = pow(d, 0.5);
		//					circle *c=new circle(cordinates, col, cordinates.size(), r);//correct color
		//					c->draw();
		//					allshapes.push_back(c);
		//				}
		//			}
		//		}
		//		cordinates.clear();
		//	}
		//	if (mouse_x > -475 && mouse_x < -425 && mouse_y < 400 && mouse_y>350)
		//	{
		//		lineClicked  = true;
		//		style = true;
		//	}
		//	if (mouse_x > -415 && mouse_x < -360 && mouse_y < 400 && mouse_y> 350)
		//	{
		//			lineClicked = true;
		//			style = false;

		//	}
		//	if(lineClicked == true)
		//	{
		//		switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) {
		//		case GP142_MOUSE:
		//			col = color_detect(mouse_x, mouse_y);
		//		}
		//		while (line_p.size() != 2)
		//		{
		//			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed))
		//			{
		//			case GP142_MOUSE:
		//				Point cod_l;
		//				cod_l.x = mouse_x;
		//				cod_l.y = mouse_y;
		//				line_p.push_back(cod_l);
		//				if (line_p.size() == 2)
		//				{
		//					line* l=new line(line_p, col, line_p.size(), style);//correct the color and style.
		//					l->draw();
		//					allshapes.push_back(l);
		//					
		//				}
		//			}
		//		}
		//		line_p.clear();
		//		lineClicked = false;
		//	}
			if (mouse_x > -475 && mouse_x < -425 && mouse_y < 280 && mouse_y> 230)
			{
				switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) {
				case GP142_MOUSE:
					col = color_detect(mouse_x, mouse_y);
				}
				while (rec_p.size() != 2)
				{
					switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed))
					{
					case GP142_MOUSE:
						Point cod_r;
						cod_r.x = mouse_x;
						cod_r.y = mouse_y;
						rec_p.push_back(cod_r);
						if (rec_p.size() == 2)
						{
							rectangle * r= new rectangle(rec_p, col, rec_p.size(), 0);//correct the color and style and fill color;
							r->draw();
							allshapes.push_back(r);
						}
					}
				}
				rec_p.clear();
			}
		//	if (mouse_x > -475 && mouse_x < -425 && mouse_y < 160 && mouse_y> 110)
		//	{
		//		switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) {
		//		case GP142_MOUSE:
		//			col = color_detect(mouse_x, mouse_y);
		//		}
		//		while (key_pressed != '.')//right click check
		//		{
		//			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed))
		//			{
		//			case GP142_MOUSE:
		//				Point cod_p;
		//				cod_p.x = mouse_x;
		//				cod_p.y = mouse_y;
		//				poly_p.push_back(cod_p);
		//			case GP142_KBD:
		//				handle_kbd(key_pressed);
		//				if (key_pressed == '.')
		//				{
		//					polygon* p=new polygon(poly_p, col, poly_p.size(), 0);//correct the color and style and fill color;
		//					p->draw();
		//					allshapes.push_back(p);
		//				}
		//			}
		//		}
		//		poly_p.clear();
		//	}
		//	if (mouse_x > -475 && mouse_x < -425 && mouse_y < 220 && mouse_y> 170)
		//	{
		//		switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) {
		//		case GP142_MOUSE:
		//			col = color_detect(mouse_x, mouse_y);
		//		}
		//		while (key_pressed!='.')//curve_p.size() != 4)//right click check
		//		{
		//			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed))
		//			{
		//			
		//			case GP142_MOUSE:
		//				if (key_pressed != '.' )
		//				{
		//					Point cod_cr;
		//					cod_cr.x = mouse_x;
		//					cod_cr.y = mouse_y;
		//					curve_p.push_back(cod_cr);
		//				}
		//			case GP142_KBD:
		//				handle_kbd(key_pressed);
		//				if (key_pressed == '.')
		//				{
		//					curve* cr=new curve(curve_p, col, curve_p.size(), "true");//correct the color and style and fill color;
		//					cr->draw();
		//					allshapes.push_back(cr);
		//				}
		//			
		//			
		//			}
		//		}
		//		curve_p.clear();
		//	}
		//	//dotted
		//	
		//	//text
		//	
		///*	if (mouse_x > -475 && mouse_x < -425 && mouse_y < -80 && mouse_y> -130)
		//	{
		//		switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) {
		//		case GP142_MOUSE:
		//			col = color_detect(mouse_x, mouse_y);
		//		}
		//		while (key_pressed != '.')
		//		{
		//			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed))
		//			{
		//			case GP142_MOUSE:
		//				Point p_t;
		//				p_t.x = mouse_x;
		//				p_t.y = mouse_y;
		//				p_text.push_back(p_t);
		//			case GP142_KBD:
		//				handle_kbd(key_pressed);
		//				if ((key_pressed != 0) && (key_pressed != 46))
		//				{
		//					texting.push_back(key_pressed);
		//				}
		//				if (key_pressed == '.')
		//				{
		//					text* t = new text(p_text, col, 1, texting);
		//					t->draw();
		//					allshapes.push_back(t);
		//				}


		//			}
		//		}
		//	}*/
			if (mouse_x > -475 && mouse_x < -425 && mouse_y < 40 && mouse_y> -10)
			{
				switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed))
				{
				case GP142_MOUSE:
					Point p_cont;
					p_cont.x = mouse_x;
					p_cont.y = mouse_y;

					if (allshapes[0]->contains(p_cont) == true)
					{
						allshapes[0]->fill(18, p_cont);
					}
					
				}
			}
			

			//draw_circle(mouse_x,mouse_y,10);
			break;

		case GP142_KBD:
			//Keyboard handler
			handle_kbd(key_pressed);
			break;

		default:
			break;
		}
	}


	//int pcount=0;
	//int points[4];
 //  
 //   //The Event Loop  
 //   while (!quit) {
 //   
 //       switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) {
 //           case GP142_QUIT:
 //               quit = 1;   /* set flag to terminate loop                
 //               break;
 //  
	//		case GP142_MOUSE:
 //               //handle_mouse(mouse_x,mouse_y);
	//			
	//			points[2*pcount]=mouse_x;
	//			points[2*pcount+1]=mouse_y;
	//			pcount++;

	//			if(pcount==2)
	//			{
	//				pcount=0;
	//				draw_line(points[0],points[1],
	//					      points[2],points[3]);
	//			}

	//			


	//			//draw_circle(mouse_x,mouse_y,10);
 //               break;
 //              
 //           case GP142_KBD:
	//			//Keyboard handler
 //               handle_kbd(key_pressed);
 //               break;
 //
 //           default:
 //               break;
 //       }
 //   }
 //       
	GP142_close();          /* Clean up and close graphics window           */

	return 0;
}







/*
				points[2*pcount]=mouse_x;
				points[2*pcount+1]=mouse_y;
				pcount++;

				if(pcount==2)
				{
					pcount=0;
					draw_line(points[0],points[1],
							  points[2],points[3]);
				}*/



				//draw_circle(mouse_x,mouse_y,10);


