import turtle

# Function to draw a point
def draw_point(x, y, color="black"):
    turtle.penup()
    turtle.goto(x, y)
    turtle.dot(5, color)

# Function to draw the triangle
def draw_triangle(points):
    turtle.penup()
    turtle.goto(points[0])
    turtle.pendown()
    turtle.goto(points[1])
    turtle.goto(points[2])
    turtle.goto(points[0])
    turtle.penup()

# Set up the screen
turtle.setup(width=600, height=600)
turtle.speed(0)

# Define triangle vertices
a = (0, 100)
b = (-50, 0)
c = (50, 0)

# Draw the triangle
draw_triangle([a, b, c])

# Points inside the triangle
inside_points = [(0, 50), (-10, 20), (20, 30)]
for point in inside_points:
    draw_point(point[0], point[1], "green")

# Points outside the triangle
outside_points = [(0, 110), (-60, 0), (60, -10)]
for point in outside_points:
    draw_point(point[0], point[1], "red")

# Points on the edges of the triangle
edge_points = [(0, 0), (-25, 50), (25, 50)]
for point in edge_points:
    draw_point(point[0], point[1], "blue")

# Hide the turtle and display the window
turtle.hideturtle()
turtle.done()
