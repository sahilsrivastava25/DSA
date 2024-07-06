class Solution
{
public:
  int passThePillow(int n, int time)
  {
    if (n == time)
      return (n - 1);

    else if (n > time)
      return (time + 1);

    int start = 0;
    int ans;

    if (n < time)
    {
      while (time)
      {
        if (time > n)
        {
          time = time - n + 1;

          if (start == 0)
            start = 1;

          else
            start = 0;
        }

        else if (time < n)
        {
          if (start == 0)
          {
            ans = time + 1;
            break;
          }

          else
          {
            ans = n - time;
            break;
          }
        }

        else{
          if (start == 0)
          {
            ans = n - 1;
            break;
          }

          else
          {
            ans = 2;
            break;
          }
        }
      }  
    }
    return ans;
  }
};