import unittest

from merge_sort import merge_sort


class MergeSortTestCase(unittest.TestCase):
    def test_on_random_list(self):
        data = [5, 2, 1, 3, 4, 13, 52, 4]
        self.assertEqual(merge_sort(data), [1, 2, 3, 4, 4, 5, 13, 52])

    def test_on_sorted_list(self):
        data = [1, 2, 3, 4, 5]
        self.assertEqual(merge_sort(data), [1, 2, 3, 4, 5])


if __name__ == '__main__':
    unittest.main()
