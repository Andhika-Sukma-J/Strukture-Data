#include <iostream>
using namespace std;
int main()
{
char chars[8] = {'a', 'a', 'b', 'b','b', 'c', 'c', 'c'};
int length = 8;
char result[2 * length];
int j = 0;
for (int i = 0; i < length; ++i)
{
result[j++] = chars[i];
int count = 1;
while (i + 1 < length && chars[i] == chars[i + 1])
{
count++;
++i;s
}
if (count > 1)
{
result[j++] = count + '0';
}
}
cout << "Output : " << j << ", [";
for (int i = 0; i < j; ++i)
{
cout << "'" << result[i] << "'";
if (i < j - 1) cout << ", ";
}
cout << "]\n";
return 0;
}
