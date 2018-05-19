#ifndef INDEXMINHEAP_H_INCLUDED
#define INDEXMINHEAP_H_INCLUDED
template<typename Item>
class IndexMinHeap
{
private:
    Item *data;
    int *indexes;
    int *reverse;
    int count=0;
    int capacity;
    void shiftUp(int k)
    {
        while(k/2>=1)
        {
            if(data[indexes[k]]<data[indexes[k/2]])
            {
                swap(indexes[k],indexes[k/2]);
                reverse[indexes[k]]=k;
                reverse[indexes[k/2]]=k/2;
            }
            else
                break;
            k/=2;
        }
    }
    void shiftDown(int k)
    {
        while(2*k<=count)
        {
            int j=2*k;
            if(j+1<=count&&data[indexes[j]]>data[indexes[j+1]])
                j++;
            if(data[indexes[k]]>data[indexes[j]])
            {
                swap(indexes[k],indexes[j]);
                reverse[indexes[k]]=k;
                reverse[indexes[j]]=j;
            }
            else
                break;
            k=j;
        }
    }
public:
    IndexMinHeap(int capacity)
    {
        this->capacity=capacity;
        data=new Item[capacity+1];
        indexes=new int[capacity+1];
        reverse=new int[capacity+1];
        for(int i=0;i<=capacity;i++)
          reverse[i]=0;
    }
    IndexMinHeap(Item arr[],int n)
    {
        data=new Item[n+1];
        capacity=n;

        for(int i=0;i<n;i++)
            data[i]=arr[i];
        count=n;
        for(int i=count/2;i>=1;i--)
            shiftDown(i);

    }
    ~IndexMinHeap()
    {
        delete[]data;
        delete[]indexes;
        delete[]reverse;
    }
    int size()
    {
        return count;
    }
    bool isEmpty()
    {
        return 0==count;
    }
    void insert(int i,Item item)
    {
        assert(count+1<=capacity);
        assert(i+1>=1&&i+1<=capacity);

        i+=1;
        data[i]=item;
        indexes[count+1]=i;
        reverse[indexes[i]]=count+1;
        count++;
        shiftUp(count);
    }
    Item extractMin()
    {
        assert(count>0);

        Item ret=data[indexes[1]];
        swap(indexes[1],indexes[count]);
        reverse[indexes[1]]=1;
        reverse[indexes[count]]=0;
        count--;
        shiftDown(1);
        return  ret;
    }
    int extractMinIndex()
    {
        assert(count>0);
        int ret=indexes[1];
        swap(indexes[1],indexes[count]);
        reverse[indexes[1]]=1;
        reverse[indexes[count]]=0;
        count--;
        shiftDown(1);
        return ret;
    }
    Item getMin()
    {
        assert(count>0);
        return data[indexes[1]];
    }
    int getMinIndex()
    {
        assert(count>0);
        return indexes[1]-1;
    }
    bool contain(int index)
    {
        return reverse[indexes[index]]!=0;
    }
    Item getItem(int index)
    {
        assert(contain(index+1));
        return data[index+1];
    }
    void change(int index,Item newItem)
    {
        assert(contain(index));
        index+=1;
        data[indexes[index]]=newItem;

        shiftUp(reverse[index]);
        shiftDown(reverse[index]);
    }

};


#endif // INDEXMINHEAP_H_INCLUDED
