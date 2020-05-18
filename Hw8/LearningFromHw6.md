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
friend std::istream & operator>>(std::istream is, Phone & item); // It is for non-member function 
// but by using keyword "friend" it can use looks like member function 
// because friend function can acess the member variable

std::ostream & operator<<(std::ostream & os, PhoneSpec::Type type)
{
    os << Type_cstr[static+cast<size_t>(type)];
    return os;
}
/// like this, we can make operator overloading. in this code we return ostream
</code>
</pre>

## Input / Output
1. std::iostream
-  std::cin , operator>>
- the reason why we can use cin regardless of type is because of operator >>
- operator >> is a overloading function so that can already overloaded by all type 
- we cannot use type string for operator >> but we can use when we overload code like this
<pre>
<code>
istream& operator>>(istream& in, std::string& s)
{
    //implement
}
</code>
</pre>
- more detail of istream [Link](https://modoocode.com/213)

2. FILE I/O ==> fstream
**==> ifstream**
    1. open
    - void open(const char* fileName, ios_base::openmode mode = ios_base::in);
        - ios_base::in   : open file for read
        - ios_base::out  : open file for write
        - ios_base::binary : open file by binary type
    2. is_open
    - bool is_open() const;
        - check file is open or not
    3. close
    - void close();
        - close the file
    4. get
    - istream& get (char& c);
        - read character from file and put character to c
    <pre>
    <code>
    char c;
    while(readFile.get(c))
    {
        cout<<c;
    }
</code>
    </pre>
    5. getline
    - ifstream& getline(char* str, streamsize len);
    6. eof
    - bool eof() const;

**==> ofstream**
    1. write 
    - ostream& write(const char* str, streamsize n);

## Exception Handling
1. syntax
<pre>
<code>
try
{
    // code
    // if error or some condition occur ==> use "throw"
}
catch
{
    // when throwing occur ==> catch that
}
catch(...)
{
    /// for unexpected error
}
</code>
</pre>
2. exception - root class for all standard exception
- logic_error
    - invalid_argument : for invalid function argument
    - out_of_range : out of range array indices
- runtime_error
    - overflow_error : mathematical overflow
    - bad_alloc : memory allocation failure
