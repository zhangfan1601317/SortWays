#ifndef INDEXMAXHEAP_H_INCLUDED
#define INDEXMAXHEAP_H_INCLUDED

template<typename Item>
class IndexMaxHeap
{
private:
    Item *data;
    int *indexes;
    int *reverse;

    int count;
    int capacity;
    void shiftUp(int k)//me
    {
        for(int i=k;i>1;i/=2)
        {
            if(data[indexes[i]]>data[indexes[i/2]])
            {
                swap(indexes[i],indexes[i/2]);
                reverse[indexes[i/2]]=i/2;
                reverse[indexes[i]]=i;
            }

            else
                break;
        }
    }
    void shiftUp2(int k)//wrong
    {
        int i=k;
        Item e=data[indexes[i]];
        int index=indexes[i];
        while(i>1)
        {
            if(e>data[indexes[i/2]])
                indexes[i]=indexes[i/2];
            else
                break;

            i/=2;
        }
        swap(indexes[i],index);
    }
    void shiftDown(int k)
    {
      while(k*2<=count)
      {
          int j=k*2;
          if(j+1<=count&&data[indexes[j]]<data[indexes[j+1]])
            j++;
          if(data[indexes[k]]>=data[indexes[j]])
            break;
          else
          {
              swap(indexes[k],indexes[j]);
              reverse[indexes[k]]=k;
              reverse[indexes[j]]=j;
          }

          k=j;
      }
    }
    void shiftDown2(int k)//wrong
    {
        Item e=data[indexes[k]];
        int index=indexes[k];
        while(k*2<=count)
        {
            int j=2*k;
            if(j+1<=count&&data[indexes[j]]<data[indexes[j+1]])
                j++;
            if(e>=data[indexes[j]])
                break;
            else
                indexes[k]=indexes[j];
            k=j;
        }
        swap(indexes[k],index);
    }
public:
    IndexMaxHeap(int capacity)
    {
        data=new Item[capacity+1];
        indexes=new int[capacity+1];
        reverse=new int[capacity+1];
        for(int i=0;i<=capacity;i++)
            reverse[i]=0;
        count=0;
        this->capacity=capacity;
    }
    IndexMaxHeap(Item arr[],int n)
    {
        data=new Item[n+1];
        for(int i=0;i<n;i++)
            data[i+1]=arr[i];
        count=n;
        for(int i=count/2;i>0;i--)
            shiftDown(i);
            //shiftDown2(i);
    }
    ~IndexMaxHeap()
    {
        delete[]data;
        delete[]indexes;
        delete[] reverse;
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
        reverse[i]=count+1;
        count++;
        shiftUp(count);
        //shiftUp2(count);
    }
    Item extractMax(){
        assert( count > 0 );

        Item ret = data[indexes[1]];
        swap( indexes[1] , indexes[count] );
        reverse[indexes[1]]=1;
        reverse[indexes[count]]=0;
        count--;
        shiftDown(1);
        return ret;
    }
    Item extractMax0()
    {
        assert(count>=0);

        Item ret=data[indexes[1]];
        swap(indexes[count],indexes[1]);
        reverse[indexes[1]]=1;
        reverse[indexes[count]]=0;
        count--;
        shiftDown(1);
        //shiftDown2(1);

        return ret;
    }
    int extractMaxIndex()
    {
        assert(count>=0);

        int ret=indexes[1]-1;
        swap(indexes[count],indexes[1]);
        count--;
        shiftDown(1);
        //shiftDown2(1);

        return ret;
    }
    Item getMax()
    {
        assert(count>0);
        return data[indexes[1]];
    }
    int getMaxIndex()
    {
        assert(count>0);
        return indexes[1]-1;
    }
    bool contain(int i)
    {
        return reverse[i+1]!=0;
    }
    Item getItem(int i)
    {
        assert(contain(i));
        assert(i+1>=1&&i+1<=capacity);
        return data[i+1];
    }
    void change(int i,Item newItem)
    {
        assert(contain(i));
        i+1=1;
        data[i]=newItem;
//        for(int j=1;j<=count;j++)
//        {
//            if(indexes[j]==i)
//            {
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }
//        }
        int j=reverse[i];
        shiftDown(j);
        shiftUp(j);
    }
    void printMaxHeap()
    {
        for(int i=0;i<count;i++)
            cout<<data[i+1]<<" ";
        cout<<endl;
    }
};

#endif // INDEXMAXHEAP_H_INCLUDED
