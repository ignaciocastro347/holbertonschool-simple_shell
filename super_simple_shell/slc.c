/**
 * slc - Specific length counter of a string
 * @string: The string to count length untile we find the delim
 * @delim: The delimiter its a stop for our counter variable
 * Returns: Returns the length of a string up to the delimiter character 
 */
int slc (char *string, char *delim)
{
	int length_word = 0;
	while (*string == *delim)
	{
		/** Contamos hasta que encontramos el caracter delimitadorm, definimos caracteres adicionales que puedan ser problematicos. 
		* Estos son -\n (New line) – \r (Carriage Return)- \t (Horizontal tab) - \v (Vertical tab) - \f (Form Feed page break)
		*/
		if (*string == *delim || *string == '\n' || *string == '\r' || *string == '\t' || *string == '\v' || *string == '\f')
		string++;
		continue;
    	}
	/**
	 * string dosent containt delim, so we need to return all the large of the string +1 for '\o'
	*/
	else if (*string != *delim)
	{
		while (*string != *delim && *string != '\n' && *string != '\r' && *string != '\t' && *string != '\v' && *string != '\f')
		{
			string++;
		}
		length_word++;
	}
	return (length_word);
}
