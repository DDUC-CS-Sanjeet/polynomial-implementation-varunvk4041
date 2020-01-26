#include<iostream>
using namespace std;

class Polynomial
{
  private:
    // Variables to store information about polynomial
    int degree;
    int *poly;
  public:
    Polynomial()
    {
      // Behavior of default constructor
      degree = 0;
      poly = new int[1];
      poly[0] = 0;
    }

    Polynomial(int deg)
    {
      // Behavior of constructor with arguments
      degree = deg;
      poly = new int[degree+1];
    }
  
    ~Polynomial()
    {
      // Behavior of destructor
      delete poly;
    }
  
    //  Overload copy constructor, +, - and = operators
    Polynomial(const Polynomial &obj)
    {
        degree = obj.degree;
        poly = new int[degree+1];
    }
    // Overloaded + operator
    Polynomial operator+(const Polynomial &obj)
    {
       int max_deg = max( this->degree,obj.degree );
       int min_deg = min( this->degree,obj.degree );
       int i=max_deg, j=min_deg;
       Polynomial temp(max_deg);
       if( this->degree == obj.degree )
       {
         while( i>=0 )
         {
           temp.poly[i] = this->poly[i] + obj.poly[i];
           i--;
         }
       }
       else if( this->degree > obj.degree )
       {    
          while( j>=0 )
          {
            temp.poly[i] = this->poly[i] + obj.poly[j]; 
            i--;
            j--;
          }
          while( i>=0 )
          {
            temp.poly[i] = poly[i];
            i--;
          }
       }
       else
       {
         while( j>=0 )
          {
            temp.poly[i] = this->poly[j] + obj.poly[i]; 
            j--;
            i--;
          }
          while( i>=0 )
          {
            temp.poly[i] = obj.poly[i];
            i--;
          }
       }
       return temp;  
    }
    // Overloaded - operator
    Polynomial operator-(Polynomial &obj)
    {
       int max_deg = max( this->degree,obj.degree );
       int min_deg = min( this->degree,obj.degree );
       int i=max_deg, j=min_deg;
       Polynomial temp(max_deg);
       if( this->degree == obj.degree )
       {
          while( i>=0 )
         {
           temp.poly[i] = this->poly[i] - obj.poly[i];
           i--;
         }
       }
       else if( this->degree > obj.degree )
       {    
          while( j>=0 )
          {
            temp.poly[i] = this->poly[i] - obj.poly[j]; 
            i--;
            j--;
          }
          while( i>=0 )
          {
            temp.poly[i] = poly[i];
            i--;
          }
       }
       else
       {
         while( j>=0 )
          {
            temp.poly[i] = this->poly[j] - obj.poly[i]; 
            j--;
            i--;
          }
          while( i>=0 )
          {
            temp.poly[i] = -obj.poly[i];
            i--;
          }
       }
       return temp;  
    }
    
    // Overloaded = operator
    void operator=(const Polynomial &obj)
    {
        degree = obj.degree;
        poly = new int[degree+1];
        for(int i=0; i<=degree; i++)
        {
          poly[i] = obj.poly[i]; 
        }
    }
    void storePolynomial()
    {
      //  Code to enter and store polynomial
      int temp_deg = degree;
      for(int i=0; i<=degree; i++)
      {
        cout<<"\nEnter coefficient of (X^"<<temp_deg--<<")";
        cin>>poly[i];
      }
      cout<<"\n";
    }
    void display()
    {
      //  Code to print the polynomial in readable format
      int temp_deg = degree;
      for(int i=0; i<=degree; i++)
      {
          cout<<"("<<poly[i]<<"X^"<<temp_deg--<<")";
          if(!(temp_deg<0))
          {
              cout<<" + ";
          }
      }
      cout<<"\n";
    }
};

int main()
{
  int degFirst, degSecond;
  // Ask user to input the values of degFirst and degSecond 
  cout<<"Enter degree of first polynomial ";
  cin>>degFirst;
  cout<<"\nEnter degree of second polynomial ";
  cin>>degSecond;
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial;
  
  cout<<"Enter first polynomial\n";
  firstPolynomial.storePolynomial();
  cout<<"\nEnter second polynomial\n";
  secondPolynomial.storePolynomial();
  
  thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
  cout<<"\nFirst polynomial =>";
  firstPolynomial.display();
  cout<<"\nSecond polynomial =>";
  secondPolynomial.display();
  cout<<"\nThird polynomial =>";
  thirdPolynomial.display();
  cout<<"\nFourth polynomial =>";
  fourthPolynomial.display();
  return 0;
}
