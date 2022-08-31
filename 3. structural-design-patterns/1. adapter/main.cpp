/*
  Here, you can see an example of an adapter which convers a square to rectangle
*/

struct Square
{
  int side{ 0 };


  explicit Square(const int side)
    : side(side)
  {
  }
};

struct Rectangle
{
  virtual int width() const = 0;
  virtual int height() const = 0;

  int area() const
  {
    return width() * height();
  }
};

struct SquareToRectangleAdapter : Rectangle
{
  SquareToRectangleAdapter(const Square& square)
    : sideLen(square.side)
  {
      // todo
  }
  
  int width() const override { return sideLen; }
  int height() const override { return sideLen; }
  
private:
    int sideLen;
};

int main() {
  return 0;
}
