
int merge(vector<int> &v, int low, int mid, int high)
{
   vector<int> temp;
   int left = low;
   int c=0;
   int right = mid+1;
   while(left<=mid && right <= high)
   {
      if(v[left] <= v[right])
      {
         temp.pb(v[left]);
         left++;
      }
      else
      {
         temp.pb(v[right]);
         c+=(mid - left +1);
         right++;
      }
   }
   while(left<=mid)
   {
      temp.pb(v[left]);
      left++;
   }
   while(right<=high)
   {
      temp.pb(v[right]);
      right++;
   }

   for(int i=low;i<=high;i++)
   {
      v[i] = temp[i-low];
   }
   return c;
}

int mergesort(vector<int> &v, int low, int high)
{
   int c=0;
    if(low>=high)
   {
      return c;
   }
   int mid = (low+high)/2;
   c += mergesort(v,low, mid);
   c += mergesort(v,mid+1, high);
   c += merge(v,low, mid, high);
   return c;
}
