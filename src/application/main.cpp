#include <tronapplication.h>
#include <application.h>

int main(int argc, char **argv)
{
  int result;
  Application *app = new TronApplication;
  result = app->init();
  if(result == 0)
  {
    result = app->run();
  }
  delete app;
  return result;
}

