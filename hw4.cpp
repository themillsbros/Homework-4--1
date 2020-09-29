#include "recursive.h"
#include "hw4.h"

int accumulate(list_t l, int (*fn)(int, int), int base){
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}

/*sum
helper: if list empty return running sum
otherwise pass rest of list and running sum plus first
sum: run helper
*/
static int sumHelper(list_t list, int run_sum){
  if(list_isEmpty(list)){

    return run_sum;
}

  return sumHelper(list_rest(list), run_sum + list_first(list));
}

int sum(list_t list){

    return sumHelper(list, 0);
}

/* product
helper: if list empty return running product
otherwise pass rest of list and running product times first
product: run helper
*/
static int productHelper(list_t list, int run_prod){

  if(list_isEmpty(list)){

    return run_prod;
  }

  return productHelper(list_rest(list), run_prod * list_first(list));
}

int product(list_t list){

  return productHelper(list, 1);
}


/*
reversehelper: if list is empty add last element to the front, pass reversed list
other wise push first onto running list
pass next element to be pushed, running list, and old list
reverse: if empty return empty list
otherwise, make running list
pass first of old list, running list, and rest of old list to the helper
*/

static list_t reverseHelper(int element, list_t new_list, list_t old_list){

  if(list_isEmpty(old_list)){
    new_list = list_make(element, new_list);
    return new_list;
  }
  new_list = list_make(element, new_list);
  return reverseHelper(list_first(old_list), new_list, list_rest(old_list));
}

list_t reverse(list_t list){

  if(list_isEmpty(list)){
    return list;
  }
  list_t reverseList = list_make();
  return reverseHelper(list_first(list), reverseList, list_rest(list));

}

/*
append: if lists empty, return other
use reverse function on list 1
pass the first of list1, list 2, amd rest of first
helper: recusively push elements of list 1 onto list 2 until list1 is no more
*/
static list_t appendHelper(int element, list_t list2, list_t list1){

  if(list_isEmpty(list1)){
    list2 = list_make(element, list2);
    return list2;
  }
  list2 = list_make(element, list2);
  return appendHelper(list_first(list1), list2, list_rest(list1));
}

list_t append(list_t first, list_t second){
  if(list_isEmpty(first)){
    return second;
}
  if(list_isEmpty(second)){
    return first;
}
  first = reverse(first);
  return appendHelper(list_first(first), second, list_rest(first));

}

/*
filter_odd:if empty list return empty list
otherwise make fresh list
pass fist element, fresh list, and rest of old list to helper
helper: check if elements are odd, push onto running list, pass rest pf list until old list empty. Then reverse list because it is backwards.
*/
static list_t filter_oddHelper(int element, list_t newOddList, list_t oldList){
  if(list_isEmpty(oldList)){
    if(element%2 != 0){
      newOddList = list_make(element, newOddList);
    }
    newOddList = reverse(newOddList);
    return newOddList;
  }
  if(element%2 != 0){
     newOddList = list_make(element, newOddList);
  }
  return filter_oddHelper(list_first(oldList), newOddList, list_rest(oldList));
}


list_t filter_odd(list_t list){
  if(list_isEmpty(list)){
    return list;
  }
  list_t oddList = list_make();
  return filter_oddHelper(list_first(list), oddList, list_rest(list));
}

/*filter_even
same as odd but checking for no remaider on check.
*/
static list_t filter_evenHelper(int element, list_t newEvenList, list_t oldList){
  if(list_isEmpty(oldList)){
    if(element%2 == 0){
       newEvenList = list_make(element, newEvenList);
      }
    newEvenList = reverse(newEvenList);
    return newEvenList;
  }
  if(element%2 == 0){
    newEvenList = list_make(element, newEvenList);
  }
  return filter_evenHelper(list_first(oldList), newEvenList, list_rest(oldList));
}

list_t filter_even(list_t list){
  if(list_isEmpty(list)){
    return list;
  }
  list_t evenList = list_make();
  return filter_evenHelper(list_first(list), evenList, list_rest(list));
}



/*rotate
test if n=0 or list empty
pass first element, n for given amount of rotation, fresh list, and rest of old list to helper

helper: couldnt figure out. somehow push old list onto  fresh list n amount of times
*/   
static list_t rotateHelper(int element, int count, list_t newList, list_t existingList){
  return 0;
}

//recursive fib
int fib(int n){
  if(n == 0){
  return 0;
  }
  if (n == 1){
  return 1;
  }
  return fib(n-1)+fib(n-2);
}

//tail recursive
int fib_tailHelper(int n, int var1, int var2){
if(n == 0){
return var1;
}
if(n == 1){
return var2;
}
return fib_tailHelper(n-1, var2, (var1+var2));
}

int fib_tail(int n){
  int var1 = 0;
  int var2 = 1;
  
return fib_tailHelper(n, var1, var2);
}