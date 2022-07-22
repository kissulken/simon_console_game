#pragma once

class Constants
{
	public:
		enum Component_X_Positions { X_position_1 = 19, X_position_2 = 37, X_position_3 = 55, X_position_4 = 73, X_position_5 = 91 };
		enum Directions { UpB, LeftB, RightB, DownB, ZeroB };
		enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, zerobutton = 48 };
		enum Arrows { LEFT_ARROW, RIGHT_ARROW, DOWN_ARROW, UP_ARROW, NUM_ZERO };
		enum Animations { AnimLeft, AnimRight, AnimDown, AnimUp };
		enum TypeOfAnimation {UpAnimation, DownAnimation, LeftAnimation, RightAnimation, ZeroAnimation};
		enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
		static const int LIGHTER_WIDTH = 8;
		static const int LIGHTER_HEIGHT = 4;
		static const int ANIMATION_BLOCK_WIDTH = 6;
		static const int ANIMATION_BLOCK_HEIGHT = 2;
		static const int BORDER_SIZE = 1;
		static const char BORDER_MATERIAL = '*';
		static const int NUMBER_OF_LIGHTERS = 5;
		static const int START_AMOUNT_OF_LIGHTUPS = 3;
		static const int LIGHTER_POSITION_Y = 3;
		static const int TIME_TO_SPAWN = 50;
		static const int ARROW_POSITION_Y = 10;
		static const int COUNTERS_POSITION_Y = 15;
		static const int BASIC_HP = 3;
		static const int BASIC_POINTS = 0;
		static const int ARROW_WIDTH = 8;
		static const int ARROW_HEIGHT = 2;
};



