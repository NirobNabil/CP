all_of()
any_of()
none_of()
copy_n()
iota()
accumulate(a, a+3, sum, std::minus<int>()); 
partial_sum(a , a+5 , b);

adjacent_difference (a, a+6, b);
adjacent_difference (a, a+6, b, myfun);
adjacent_difference (a, a+6, b, multiplies<int>() ) ;

inner_product(a, a+3, b, var, minus<int>(), divides<int>()); 
replace(arr, arr + n, old_val, new_val);
transform(arr,arr+n,arr2,arr3,plus <int>())
transform(arr,arr+n,arr,increment)
*max_element(arr,arr+n)
accumulate(arr,arr+n,var)
count(arr,arr+n,x)
lower_bound(x)