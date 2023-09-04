// https://revel-ise.pearson.com/courses/64c850238ffa173ef7de0daf/assignments/1ed5f39f-0485-48bb-ab19-440a74970935/pages/urn:pearson:entity:e3d65146-afdf-4452-873a-17efe3ba7f4b?source=dashboard
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
  Circle();
  Circle(double);
  double getArea();
  double getRadius();
  void setRadius(double); 

private:
  double radius;
};

#endif