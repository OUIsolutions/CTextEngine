
void create_html(const char *props, int data){
    
    struct CText *stack = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
      stack->OPEN(stack,HTML);
        stack->open(stack,BODY);
            stack->open(stack,H1);
                stack->text(stack,"Hello World");
            stack->close(stack,H1);
        stack->close(stack,BODY);
    stack->close(stack,HTML);

  
    stack->open(stack,HTML);
        stack->open(stack,BODY);
            stack->open(stack,H1);
                stack->text(stack,"Hello World");
            stack->close(stack,H1);
        stack->close(stack,BODY);
    stack->close(stack,HTML);

    CTEXT_OPEN(stack,HTML);
        CTEXT_OPEN(stack,BODY);
            CTEXT_OPEN(stack,H1);
                CTEXT_TEXT(stack,"Hello World");
            CTEXT_CLOSE(stack,H1);
        CTEXT_CLOSE(stack,BODY);
    CTEXT_CLOSE(stack,HTML);


    ctext_open(stack,HTML);
        ctext_open(stack,BODY);
            ctext_open(stack,H1);
                ctext_text(stack,"Hello World");
            ctext_close(stack,H1);
        ctext_close(stack,BODY);
    return stack;
}
