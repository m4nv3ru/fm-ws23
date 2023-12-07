import sys


def merge(left: list, right: list) -> list:
    merged = []
    left_index = 0
    right_index = 0

    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            merged.append(left[left_index])
            left_index += 1
        else:
            merged.append(right[right_index])
            right_index += 1

    if left_index < len(left):
        merged.extend(left[left_index:])
    elif right_index < len(right):
        merged.extend(right[right_index:])

    return merged


def merge_sort(data: list) -> list:
    if len(data) <= 1:
        return data

    mid = len(data) // 2
    left = merge_sort(data[:mid])
    right = merge_sort(data[mid:])

    return merge(left, right)


def main(file_path: str, write_output: bool = False):
    with open(file_path, 'r') as f:
        int(f.readline())
        data = f.read().split(';')
        data = list(map(int, data))

    sorted = merge_sort(data)

    if write_output:
        with open('result.txt', 'w') as f:
            f.write(str(len(sorted)) + '\n')
            f.write(';'.join(map(str, sorted)))


if __name__ == '__main__':
    # Read file given as first argument and split it into values separated by ;

    if len(sys.argv) < 2 or len(sys.argv) > 3:
        print('Usage: python merge_sort.py <file> [write_output]')
        sys.exit(1)

    if len(sys.argv) == 3:
        write_output = sys.argv[2] == 'true'
    else:
        write_output = False

    if not sys.argv[1].endswith('.txt'):
        print('File must be a .txt file')
        sys.exit(1)

    main(sys.argv[1], write_output)
