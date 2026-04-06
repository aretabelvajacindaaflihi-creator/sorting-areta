def bubble_sort(arr):
    a = arr.copy()
    n = len(a)
    print("\n=== Bubble Sort ===")
    for i in range(n):
        for j in range(0, n-i-1):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]
        print("Iterasi", i+1, ":", a)
    print("Hasil:", a)


def selection_sort(arr):
    a = arr.copy()
    n = len(a)
    print("\n=== Selection Sort ===")
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if a[j] < a[min_idx]:
                min_idx = j
        
        a[i], a[min_idx] = a[min_idx], a[i]
        print("Iterasi", i+1, ":", a)

    print("Hasil:", a)


def insertion_sort(arr):
    a = arr.copy()
    print("\n=== Insertion Sort ===")
    
    for i in range(1, len(a)):
        key = a[i]
        j = i-1

        while j >= 0 and key < a[j]:
            a[j+1] = a[j]
            j -= 1

        a[j+1] = key
        print("Iterasi", i, ":", a)

    print("Hasil:", a)


def quick_sort(arr, low, high, step=[1]):
    if low < high:
        pi = partition(arr, low, high)
        print("Iterasi", step[0], ":", arr)
        step[0] += 1

        quick_sort(arr, low, pi-1, step)
        quick_sort(arr, pi+1, high, step)


def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1


def merge_sort(arr):
    print("\n=== Merge Sort ===")
    merge_sort_process(arr.copy())


def merge_sort_process(a, step=[1]):
    if len(a) > 1:
        mid = len(a)//2
        L = a[:mid]
        R = a[mid:]

        merge_sort_process(L, step)
        merge_sort_process(R, step)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                a[k] = L[i]
                i += 1
            else:
                a[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            a[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            a[k] = R[j]
            j += 1
            k += 1

        print("Iterasi", step[0], ":", a)
        step[0] += 1

    return a


# ================== INPUT ==================
n = int(input("Masukkan jumlah data: "))

data = []
for i in range(n):
    angka = int(input(f"Masukkan angka ke-{i+1}: "))
    data.append(angka)

print("\nData awal:", data)

# ================== PROSES ==================
bubble_sort(data)
selection_sort(data)
insertion_sort(data)

print("\n=== Quick Sort ===")
quick_data = data.copy()
quick_sort(quick_data, 0, len(quick_data)-1)
print("Hasil:", quick_data)

merge_sort(data)