///////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2015 Thomas Heller
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
///////////////////////////////////////////////////////////////////////////////

#pragma warning(disable:488)
#pragma warning(disable:858)

// HPX includes
#include <hpx/hpx_main.hpp>
#include <hpx/hpx.hpp>

// Standard C++ Includes
#include <iostream>
#include <iterator>
#include <vector>

// Partition our input range
template <typename Iter>
Iter partition(Iter left, Iter right)
{
    // Determine the pivot element
    Iter mid = left + (right - left)/2;
    auto && pivot = *mid;

    Iter i = left;
    Iter j = right - 1;

    while (true)
    {
        // Move the right end to the left
        // as long as it's larger than the pivot
        //do
        while (*j > pivot)
            --j;

        // Move the left end to the right
        // as long as it's smaller than the pivot
        while (*i < pivot)
            ++i;

        // If we didn't move too far to the right, swap
        if (i < j)
            std::swap(*i, *j);
        // Otherwise return the iterator dividing the two partitions
        else
            return j;
    }
}

template <typename Iter>

hpx::future<void> quicksort(Iter begin, Iter end)
{
    if (begin < end)
    {
        // Partition
        Iter p = partition(begin, end);

        // Sort the left half asynchronously
        hpx::future<void> left = hpx::async(&quicksort<Iter>, begin, p);
        // Sort the right half asynchronously
        hpx::future<void> right = hpx::async(&quicksort<Iter>, p + 1, end);

        // Return a future that becomes ready when both partitions are sorted
        return hpx::when_all(left, right);
    }
    else
    {
        return hpx::make_ready_future();
    }
}

int main()
{
    std::vector<int> is{0, 9, 3, 56, 2, 100, 65, 200, 300, 199};

    std::cout << "Before sort: ";
    for(int i: is)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    quicksort(is.begin(), is.end()).get();
    std::cout << "After sort: ";
    for(int i: is)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
