bool init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("IITD MAZE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	// Loading success flag
	bool success = true;

	gFont = TTF_OpenFont("assets/Roboto-Medium.ttf", 28);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		// Render text
		SDL_Color textColor = {0, 0, 0};
		if (!taskTexture.loadFromRenderedText("The quick brown fox jumps over the lazy dog", textColor))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
	}


	// Load Energy bar
	for (int i = 0; i < 5; i++)
	{
		string s = "assets/energy_bar/energy_bar" + to_string(i + 1) + ".png";
		if (!(energyBarTexture[i].loadFromFile(s)))
		{
			printf("Failed to load dot texture!\n");
			success = false;
		}
	}
	// Load music
	gMusic = Mix_LoadMUS("assets/sounds/background.mp3");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gCoin = Mix_LoadWAV("assets/sounds/coin.wav");
	if (gCoin == NULL)
	{
		printf("Failed to load coin sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gCoinCollect = Mix_LoadWAV("assets/sounds/coin_collect.wav");
	if (gCoin == NULL)
	{
		printf("Failed to load coin collect sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gDog = Mix_LoadWAV("assets/sounds/dog.wav");
	if (gCoin == NULL)
	{
		printf("Failed to load dog sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gBar = Mix_LoadWAV("assets/sounds/bar_full.wav");
	if (gBar == NULL)
	{
		printf("Failed to load energy sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gYulu = Mix_LoadWAV("assets/sounds/yulu.wav");
	if (gYulu == NULL)
	{
		printf("Failed to load yulu sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gRespawn = Mix_LoadWAV("assets/sounds/respawn.wav");
	if (gRespawn == NULL)
	{
		printf("Failed to load respawn sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gDead = Mix_LoadWAV("assets/sounds/dead.wav");
	if (gDead == NULL)
	{
		printf("Failed to load dead sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	for (int i = 0; i < 8; i++)
	{
		string s = "assets/sprites/08_Elliot_RPG_Walk Left_" + to_string(i) + ".png";
		if (!(leftSpriteTexture[i].loadFromFile(s)))
		{
			printf("Failed to load dot texture!\n");
			success = false;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		string s = "assets/sprites/08_Elliot_RPG_Walk Right_" + to_string(i) + ".png";
		if (!(rightSpriteTexture[i].loadFromFile(s)))
		{
			printf("Failed to load dot texture!\n");
			success = false;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		string s = "assets/sprites/08_Elliot_RPG_Walk Up_" + to_string(i) + ".png";
		if (!(upSpriteTexture[i].loadFromFile(s)))
		{
			printf("Failed to load dot texture!\n");
			success = false;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		string s = "assets/sprites/08_Elliot_RPG_Walk Down_" + to_string(i) + ".png";
		if (!(downSpriteTexture[i].loadFromFile(s)))
		{
			printf("Failed to load dot texture!\n");
			success = false;
		}
	}

	// Load background texture
	if (!gBGTexture.loadFromFile("assets/MAP.png"))
	{
		printf("Failed to load background texture!\n");
		success = false;
	}

	if (!startTexture.loadFromFile("assets/start.png"))
	{
		printf("Failed to load background texture!\n");
		success = false;
	}

	if (!oppwinsTexture.loadFromFile("assets/oppwins.png"))
	{
		printf("Failed to load background texture!\n");
		success = false;
	}

	if (!youwinTexture.loadFromFile("assets/youwin.png"))
	{
		printf("Failed to load background texture!\n");
		success = false;
	}

	if(!coinsTexture.loadFromFile("assets/coin.png"))
	{
		printf("Failed to load background texture!\n");
		success = false;
	}

	if(!helpTexture.loadFromFile("assets/help.png"))
	{
		printf("Failed to load background texture!\n");
		success = false;
	}


	return success;
}

void close()
{
	taskTexture.free();
	scoreTextTexture.free();
	oppScoreTexture.free();
	coinsTextTexture.free();
	coinsTexture.free();

	TTF_CloseFont(gFont);
	gFont = NULL;

	// Free loaded images
	gDotTexture.free();
	gBGTexture.free();
	startTexture.free();
	oppwinsTexture.free();
    youwinTexture.free();

	for (int i = 0; i < 8; i++)
	{
		leftSpriteTexture[i].free();
		rightSpriteTexture[i].free();
		upSpriteTexture[i].free();
		downSpriteTexture[i].free();
	}

	for (int i = 0; i < 5; i++)
	{
		energyBarTexture[i].free();
	}
	// Free the sound effects
	Mix_FreeChunk(gCoin);
	gCoin = NULL;

	Mix_FreeChunk(gDead);
	gDead = NULL;

	Mix_FreeChunk(gRespawn);
	gRespawn = NULL;

	Mix_FreeChunk(gBar);
	gBar = NULL;

	Mix_FreeChunk(gYulu);
	gYulu = NULL;
	// Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	Mix_FreeChunk(gCoinCollect);
	gYulu = NULL;
	Mix_FreeChunk(gDog);
	gYulu = NULL;
	

	// Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	// Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}
