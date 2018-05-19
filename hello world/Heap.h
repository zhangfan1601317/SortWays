#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

template<typename Item>
class MaxHeap
{
private:
    Item *data;
    int count=0;
    int capacity;
    void shiftUp(int k)
    {
        for(int i=k;i>=1;i/=2)
        {
            if(data[i]>data[i/2])
                swap(data[i],data[i/2]);
        }
    }
    void shiftUp2(int k)
    {
        int i=k;
        Item e=data[i];
        while(i>=1)
        {
            if(e>data[i/2])
                data[i]=data[i/2];
            else
                break;

            i/=2;
        }
        swap(data[i],e);
    }
    void shiftDown(int k)
    {
      while(k*2<=count)
      {
          int j=k*2;
          if(j+1<=count&&data[j]<data[j+1])
            j++;
          if(data[k]>=data[j])
            break;
          else
            swap(data[k],data[j]);
          k=j;
      }
    }
    void shiftDown2(int k)
    {
        Item e=data[k];
        while(k*2<=count)
        {
            int j=2*k;
            if(j+1<=count&&data[j]<data[j+1])
                j++;
            if(e>=data[j])
                break;
            else
                data[k]=data[j];
            k=j;
        }
        swap(data[k],e);
    }
public:
    MaxHeap(int capacity)
    {
        data=new Item[capacity+1];
        count=0;
        this->capacity=capacity;
    }
    MaxHeap(Item arr[],int n)
    {
        data=new Item[n+1];
        for(int i=0;i<n;i++)
            data[i+1]=arr[i];
        count=n;
        for(int i=count/2;i>0;i--)
            //shiftDown(i);
            shiftDown2(i);
    }
    ~MaxHeap()
    {
        delete[]data;
    }
    int size()
    {
        return count;
    }
    bool isEmpty()
    {
        return 0==count;
    }
    void insert(Item item)
    {
        assert(count+1<=capacity);
        data[count+1]=item;
        count++;
        //shiftUp(count);
        shiftUp2(count);
    }
    Item extractMax()
    {
        assert(count>=0);

        Item ret=data[1];
        swap(data[count],data[1]);
        count--;
        //shiftDown(1);
        shiftDown2(1);

        return ret;
    }
    void printMaxHeap()
    {
        for(int i=0;i<count;i++)
            cout<<data[i+1]<<" ";
        cout<<endl;
    }
};

#endif // HEAP_H_INCLUDED
