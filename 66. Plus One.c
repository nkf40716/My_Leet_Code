int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
   int i = digitsSize; // start from back
   int *res = NULL;
   while (--i >= 0)
   {
	   if (digits[i] == 9)
		   digits[i] = 0;
	   else {
		   digits[i] += 1;
		   break;
	   }
   }

   if (digits[0] == 0)
   {
	   *returnSize = digitsSize + 1;
	   res = (int *)malloc(sizeof(int) * (*returnSize));
	   memcpy(res + 1, digits, sizeof(int) * digitsSize);
	   res[0] = 1;
   }
   else
   {
	   *returnSize = digitsSize;
	   res = (int *)malloc(sizeof(int) * (*returnSize));
	   memcpy(res, digits, sizeof(int) * digitsSize);
   }
   return res;
}
