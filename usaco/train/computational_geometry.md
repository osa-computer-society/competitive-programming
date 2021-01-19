# Computational Geometry

## Definitions

### Cross product

u x v = vector which is perpendicular to u and v and whose length equals $||u|| *||v||* \sin(\theta)$

- Length: area of parallelogram defined by vectrors

3D: $(u_y v_z - v_y u_z)i - (u_x v_z - u_z v_x)j + (u_x v_y - u_y v_x)k$

2D: $(u_x v_y - u_y v_x)k$

### Dot product

$u * v = u_x v_x + u_y v_y + u_z v_z$ (scalar)

= $||u|| ||v|| \cos(\theta)$

negative means obtuse, 0 perpendicular, positive acute

### Arctangent

atan2(dy, dx) gives angle between <dx, dy> and x-axis, between -pi and pi

## Debugging problems

- Geometry: lots of edge cases
- Floating point calculations
  - Check closeness instead of being exactly equal

area of triangle ABC: ||(B-A) x (C-A)|| / 2

or heron's formula: $\sqrt(s*(s-a)*(s-b)*(s-c))$ where s = sum of sidelengths / 2

Check lines parallel: vectors with cross product 0

**Area of polygon: shoelace**

```none
    x1 y1
    x2 y2
    x3 y3
    .....
    xn yn
    x1 y1
```

Take products going diagonally down and right, e.g. x1 y2, x2 y3, these are positive
diagonally down and left, e.g. y1 x2, y2 x3, these are negative
add all of these and divide by two for area

### Distance from point to line

dist from P to AB = ||AP x AB|| / ||AB||

### same side of line

Check if C, D on same side of AB:

### check if point in convex polygon O(N)

take average of vertices, this must be inside polygon

```py
x, y = 0, 0
for vx, vy in vertices:
  x += vx
  y += vy
x /= len(vertices)
y /= len(vertices)

# x, y will be inside polygon

# to check if a, b inside polygon, check if it is on same side of all edges as x, y

for i in range(vertices):
  v1x, v1y = vertices[i]
  v2x, v2y = vertices[(i+1)%len(vertices)]
  # check if a, b and x, y on same side
  # AB x AC same sign as AB x AD
  if cross(v2x - v1x, v2y - v1y, a - v1x, b - v1x) has same sign as cross(v2x - v1x, v2y - v1y, x - v1x, y - v1y):
    yes
  else:
    no
```

### check 4+ points coplanar O(N)

choose three A, B, C and for each other point P, check if scalar triple product is 0

(AB x AC) * AP = 0

### Intersecting lines O(1)

2D: check they are not parallel (nonzero cross product)

3D: lines AB and CD: if not parallel and A, B, C, D coplanar

### Line segments intersect O(1)

2D: AB and CD: iff A and B on diff sides of CD, C and D diff sides of AB

3D: solve sys. of equations

Ax + (Bx-Ax)i = Cx + (Dx-Cx)j
repeat for x, y, z and solve for i, j

### Check 2d polygon convex O(N)

```py
convex = True
for i in range(1, n):
  a, b, c = vertices[i], vertices[(i+1)%n], vertices[(i+2)%n]
  if AB x AC < 0:
    convex = False
    break
```
