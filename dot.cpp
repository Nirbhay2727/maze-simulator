Dot::Dot(int x, int y)
{
    //Initialize the offsets
    mPosX = x;
    mPosY = y;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    currentSprite =rightSpriteTexture;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {	
		changeSprite = true;
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {	
            case SDLK_UP: mVelY -= DOT_VEL; currentSprite=upSpriteTexture; break;
            case SDLK_DOWN: mVelY += DOT_VEL; currentSprite=downSpriteTexture; break;
            case SDLK_LEFT: mVelX -= DOT_VEL; currentSprite=leftSpriteTexture; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; currentSprite=rightSpriteTexture; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {	
		changeSprite = false;
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {	
			
			// currentSpriteIndex = 0;
            case SDLK_UP: mVelY = 0; 
				// currentSprite=upSpriteTexture[currentSpriteIndex/4]; 
				break;
            case SDLK_DOWN: mVelY = 0; 
				// currentSprite=downSpriteTexture[currentSpriteIndex/4]; 	
				break;
            case SDLK_LEFT: mVelX = 0;
				//  currentSprite=leftSpriteTexture[currentSpriteIndex/4]; 
				break;
            case SDLK_RIGHT: mVelX = 0; 
				// currentSprite=rightSpriteTexture[currentSpriteIndex/4]; 
				break;
        }
    }
}

void Dot::move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > LEVEL_WIDTH ) || map[mPosY/32][(mPosX + DOT_WIDTH/2)/32] == 0 || map[(mPosY+ DOT_WIDTH/2)/32][mPosX/32] == 0 || map[(mPosY+ DOT_WIDTH/2)/32][(mPosX + DOT_WIDTH/2)/32] == 0 || map[mPosY/32][mPosX/32] == 0 )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > LEVEL_HEIGHT ) || map[mPosY/32][(mPosX + DOT_WIDTH/2)/32] == 0 || map[(mPosY+ DOT_WIDTH/2)/32][mPosX/32] == 0 || map[(mPosY+ DOT_WIDTH/2)/32][(mPosX + DOT_WIDTH/2)/32] == 0 || map[mPosY/32][mPosX/32] == 0 )
    {
        //Move back
        mPosY -= mVelY;
		// cout << ( mPosY < 0 ) << endl;
		// cout << ( mPosY + DOT_HEIGHT > LEVEL_HEIGHT )  << endl;
		// cout << map[mPosY/24][(mPosX + DOT_WIDTH)/24] << endl;
		// cout << map[(mPosY+ DOT_WIDTH)/24][mPosX/24]<< endl;
		// cout << map[(mPosY+ DOT_WIDTH)/24][(mPosX + DOT_WIDTH)/24] << endl;
		// cout <<  map[mPosY/24][mPosX/24]  << endl;
		// cout << mPosY/24 << endl;
		// cout << mPosX/24 << endl;
    } 
}

void Dot::render( int camX, int camY )
{	
	
    //Show the dot relative to the camera
	currentSprite[currentSpriteIndex/4].render( mPosX - camX, mPosY - camY );
}

void Dot::renderOpponent( int camX, int camY )
{	
	
    //Show the dot relative to the camera if it is in the screen.
    if( (mPosX - camX<SCREEN_WIDTH)&&(mPosX - camX>0) &&(mPosY - camY<SCREEN_HEIGHT)&&(mPosY - camY>0)){
        // cout <<mPosX-camX<<" "<<SCREEN_WIDTH<<endl;
	    currentSprite[currentSpriteIndex/4].render( mPosX - camX, mPosY - camY );
        // cout<<"in  renderOpponent"<<camX<<camY<<mPosX<<mPosY<<endl;
    }
}

int Dot::getPosX()
{
	return mPosX;
}

int Dot::getPosY()
{
	return mPosY;
}
