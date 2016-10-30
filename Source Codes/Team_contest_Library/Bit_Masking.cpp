/*                                        BIT -masking  From http://www.shafaetsplanet.com
=======================================================================================================================*/


int Set(int N,int pos){return N=N | (1<<pos);}          /* this will set the bit of the number N at pos to 1 */
int reset(int N,int pos){return N= N & ~(1<<pos);}      /* this will set the bit of the number N at pos to 0 */
bool check(int N,int pos){return (bool)(N & (1<<pos));} /* this will return the bit of the number N at pos */
