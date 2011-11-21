#include <tronapplication.h>
#include <allegro5/allegro.h>
#include <native_dialog/allegro5/allegro_native_dialog.h>
#include <constants.h>
#include <stdio.h>

TronApplication::TronApplication()
{
  display = NULL;
  event_queue = NULL;
  timer = NULL;
}

TronApplication::~TronApplication()
{
  if(display)
    al_destroy_display(display);

  if(event_queue)
    al_destroy_event_queue(event_queue);

  if(timer)
  {
    al_destroy_timer(timer);
  }
}

int TronApplication::init(void)
{
  //Init allegro
  if(!al_init())
  {
    al_show_native_message_box(NULL, NULL, NULL,
      "Failed to initialize allegro!", NULL, NULL);
    return -1;
  }

  //Create display
  display = al_create_display(SCREEN_W, SCREEN_H);
  if(!display)
  {
    al_show_native_message_box(NULL, NULL, NULL,
      "Failed to initialize display!", NULL, NULL);
    return -1;
  }
  al_set_window_title( display, "Tron Online" );

  //Create event queue
  event_queue = al_create_event_queue();
  if(!event_queue)
  {
    al_show_native_message_box(NULL, NULL, NULL,
      "Failed to create event queue!", NULL, NULL);
    return -1;
  }

  //Create timer
  timer = al_create_timer(1.0 / FPS);
  if(!timer)
  {
    al_show_native_message_box(NULL, NULL, NULL,
      "Failed to create timer!", NULL, NULL);
    return -1;
  }

  //Register events
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));

  //Update screen
  al_clear_to_color(al_map_rgb(0,0,0));
  al_flip_display();

  return 0;
}

int TronApplication::run(void)
{
  bool redraw = true;
  al_start_timer(timer);

  while (1)
  {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    if(ev.type == ALLEGRO_EVENT_TIMER)
    {
      redraw = true;
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      break;

    if(redraw && al_is_event_queue_empty(event_queue))
    {
      redraw = false;
      al_clear_to_color(al_map_rgb(0,0,0));
      al_flip_display();
    }
  }
  return 0;
}

