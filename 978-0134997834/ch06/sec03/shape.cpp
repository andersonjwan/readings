#include <vector>

class Point {
public:
  double x;
  double y;
};

class Shape {
public:
  virtual ~Shape();

  virtual Point center() const = 0;
  virtual void move(Point to) = 0;

  virtual void draw() const = 0;
  virtual void rotate(int angle) = 0;
};

class Circle : public Shape {
public:
  Circle(Point p, int r) : center_{p}, radius_{r} {}
  ~Circle();

  Point center() const override { return center_; }
  void move(Point to) override { center_ = to; }

  void draw() const override;
  void rotate(int angle) override;

private:
  Point center_;
  int radius_;
};

class Smiley : public Circle {
public:
  Smiley(Point p, int r) : Circle(p, r), mouth{nullptr} {}
  ~Smiley() {
    delete mouth;

    for(auto s : eyes) {
      delete s;
    }
  };

  void move(Point to) override;
  void draw() const override;
  void rotate(int) override;

  void add_eye(Shape* s) {
    eyes.push_back(s);
  }

  void set_mouth(Shape* s);
  virtual void wink(int i);

private:
  std::vector<Shape*> eyes;
  Shape* mouth;
};

void
Smiley::draw() const {
  Circle::draw();

  for(auto s : eyes) {
    s->draw();
  }

  mouth->draw();
}

class Triangle : public Shape {
public:
  Triangle();
  ~Triangle();

  void draw() const override;
};

void
rotate(Shape& s, int angle) {
  s.rotate(angle);
}


