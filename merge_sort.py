# make half recursively
def merge_sort(arr, left_index, right_index) :
  if left_index >= right_index :
    return
  
  middle_index = (left_index + right_index) // 2
  merge_sort(arr, left_index, middle_index)
  merge_sort(arr, middle_index+1, right_index)
  merge(arr, left_index, right_index, middle_index)

# merging
# Think about : Is this the best logic?
def merge(arr, left_index, right_index, middle_index) :

  merged_left = arr[left_index:middle_index+1]
  merged_right = arr[middle_index + 1:right_index+1]

  merged_left_index = 0
  merged_right_index = 0
  sorted_index = left_index

  while merged_left_index < len(merged_left) and merged_right_index < len(merged_right) :
    if merged_left[merged_left_index] <= merged_right[merged_right_index] :
      arr[sorted_index] = merged_left[merged_left_index]
      merged_left_index += 1
    else :
      arr[sorted_index] = merged_right[merged_right_index]
      merged_right_index += 1
    
    sorted_index += 1
  
  while merged_left_index < len(merged_left) :
    arr[sorted_index] = merged_left[merged_left_index]
    merged_left_index += 1
    sorted_index += 1
  
  while merged_right_index < len(merged_right) :
    arr[sorted_index] = merged_right[merged_right_index]
    merged_right_index += 1
    sorted_index += 1
  
  print(arr)

# whether input can be parsed to int or not
def is_int(string) :
  try :
    int(string)
    return True
  except ValueError :
    return False

# get input and append to list if it is parsable
# if input is not parsable, start merge-sorting
def recursive_input(arr) :
  input_in = input("enter number or 'sort': ")
  if (is_int(input_in) is True) :
    arr.append(int(input_in))
    recursive_input(arr)
  else :
    merge_sort(arr, 0, len(arr))
