//**************************************************************
//
// Tron Application Class
//
//
//
//**************************************************************
#ifndef TRONAPPLICATION_H
#define TRONAPPLICATION_H
#include <application.h>

class ALLEGRO_DISPLAY;
class ALLEGRO_EVENT_QUEUE;
class ALLEGRO_TIMER;

class TronApplication : public Application
{
public:
  TronApplication();
  ~TronApplication();

  virtual int init(void);
  virtual int run(void);

protected:
private:
  ALLEGRO_DISPLAY *display;
  ALLEGRO_EVENT_QUEUE *event_queue;
  ALLEGRO_TIMER *timer;
};

#endif


