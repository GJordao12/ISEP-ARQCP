void capitalize (char *str){
    
    char offset = 65 - 97; //The diference of the a to the A position
	while (*str != '\0')
	{
		if ((*str >= 97) & (*str <= 122))
		{
			*str = *str + offset;
		}
		str++;
	}
}
