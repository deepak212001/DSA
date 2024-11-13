int ans=n;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }
        else 
            low=mid+1;  
    }
    r