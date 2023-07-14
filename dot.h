
//The dot that will move around on the screen
class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 23;
		static const int DOT_HEIGHT = 23;

		//Maximum axis velocity of the dot
		int DOT_VEL = 2;

		//Initializes the variables
		Dot(int x=0, int y=0);

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move();

		//Shows the dot on the screen relative to the camera
		void render( int camX, int camY );

		//Position accessors
		int getPosX();
		int getPosY();

		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;

		LTexture* currentSprite;

		int currentSpriteIndex = 0;

		void renderOpponent( int camX, int camY );
};

