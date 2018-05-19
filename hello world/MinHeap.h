#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED
template<typename Item>
class MinHeap
{
private:
    Item *data;
    int capacity;
    int count=0;
    void shiftUp(int k)
    {
        while(k/2>=1)
        {
            if(data[k]<data[k/2])
                swap(data[k],data[k/2]);
            else
                break;
            k/=2;
        }
    }
    void shiftDown(int k)
    {
        while(k*2<=count)
        {
            int j=2*k;
            if(j+1<=count&&data[j]>data[j+1])
                j+=1;
            if(data[k]>data[j])
                swap(data[k],data[j]);
            else
                break;
            k=j;
        }
    }
public:
    MinHeap(int capacity)
    {
        data=new Item[capacity+1];
        this->capacity=capacity;
    }
    MinHeap(Item arr[],int n)
    {
        data=new Item[n+1];
        capacity=n;

        for(int i=0;i<n;i++)
            data[i+1]=arr[i];
        count=n;
        for(int i=count/2;i>=1;i--)
            shiftDown(i);
    }
    ~MinHeap()
    {
        delete []data;
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
        shiftUp(count);
    }
    Item extractMin()
    {
        assert(count>0);
        Item ret=data[1];
        swap(data[1],data[count]);
        count--;
        shiftDown(1);
        return ret;
    }
    Item getMin()
    {
        assert(count>0);
        return data[1];
    }
};

#endif // MINHEAP_H_INCLUDED
