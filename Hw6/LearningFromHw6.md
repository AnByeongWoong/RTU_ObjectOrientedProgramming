The list of what I learned by using C++
- Operator Overloading
- Input / output
- Exception Handling 

## Operator Overloading
1. If binary operator x@y is invoked:
    - x.operator@(y) == when operator@() is a member function
    - operator@(x,y) == when operator@() is a non-member function
2. If Unary operaotr @x is invoked:
    - x.operator@() == when operator@() is a member function
    - operator@(x) == when operator@() is a non-member function

- The example what I used in this assignment
<pre>
<code>
friend std::istream & operator>>(std::istream is, Phone & item);
</code>
</pre>