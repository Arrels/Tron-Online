#ifndef DEBUG_H
#define DEBUG_H

int x = 0;

void ttrace(void)
{
  x++;
  std::cout << "Trace #" << x << std::endl;
}

#endif

