Constructor name will be same as class name, some time we need many constructors.
we make them diffent based on argument, so some time it hard to understand which to call

Named constructo mean we put our constructor in private area or protected area.
and we write static method that call inside particular constructor.

It makes easy even we not need to put a lot try catch in client code bcoz all this we can handle in named constor

class Button
{
    private:
    Button(const char* str)
    {
    
    
    }
    Button(const char* str1, const char* str2)
    {
    
    }
    public:
    static CreateButton(const char* str)
    {
        //Constrcut object and we can apply some functon that used to 
        //like set text
        //set color
        return object
    }
};
int main()
{
   Button *b = Button::CreateButton();


}
