//Praneel Misthry Computer Methods 3 -- Project Research
//The following code has been edited to allow you to animate your sprite sheets and see your sprite move
//along the screen. Remember you have to include your sprite sheet in the soln folder of your Visual Studio project
//ie the one with main.cpp in it. You will have to use some photo editing software like photoshop to get the exact frame
//dimensions of each sprite. You will also need to use photoshop to get the exact RGB values of the background of your 
//sprite. This will help us pass the background colour into the transparency function in allegro to eliminate the background
//of your sprite in the main game code. -- PM

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

int main(void)
{
	//variables
	int width = 640;
	int height = 480;
	bool done = false;

	int degree = 270; //rotation degree

	int x = width / 2;
	int y = height / 2;

	const int maxFrame = 6;
	int curFrame = 0;
	int frameCount = 0;
	int frameDelay = 10;
	int frameWidth = 129;  //Must enter this manually --128
	int frameHeight = 115; //Check the size of the images in windows to get this value --128

	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *image;

	//program init
	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);			//create our display object

	if (!display)										//test display object
		return -1;

	//addon init
	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("space_ship_kryptid-cropped.png");
	al_convert_mask_to_alpha(image, al_map_rgb(255, 162, 255));  //Make background of sprite frame transparent
	al_convert_mask_to_alpha(image, al_map_rgb(255, 255, 255));  //Make any pure white lines in frame transparent

	//Try Rotating the image each time

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60); //Set FPS to 60 FPS

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:

				break;
			case ALLEGRO_KEY_RIGHT:

				break;
			case ALLEGRO_KEY_UP:

				break;
			case ALLEGRO_KEY_DOWN:

				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (++frameCount >= frameDelay)
			{
				if (++curFrame >= maxFrame)
					curFrame = 0;

				frameCount = 0;
			}

			x -= 5;

			if (x <= 0 - frameWidth)
				x = width;
		}

		al_draw_bitmap_region(image, curFrame * frameWidth, 0, frameWidth, frameHeight, x, y, 0);

	    //Experimenting with frame rotation
		//al_draw_rotated_bitmap(image, curFrame*frameWidth / 2, frameHeight / 2, width / 2, height / 2, degree * 3.14159 / 180, 0);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}


	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}