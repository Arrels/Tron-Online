//**************************************************************
//
// Application Class
//
//
//
//**************************************************************
#ifndef APPLICATION_H
#define APPLICATION_H

class Application
{
public:
  virtual int init(void) = 0;
  virtual int run(void) = 0;

protected:
private:
};

#endif

