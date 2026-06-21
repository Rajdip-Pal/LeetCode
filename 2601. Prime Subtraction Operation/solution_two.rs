use std::cmp::Ordering;
use std::collections::HashSet;

struct Solution;

impl Solution {
    // Static primes cache to avoid recalculating primes repeatedly.
    static mut PRIMES: Option<Vec<i32>> = None;

    // Function to generate all primes up to n.
    pub fn get_primes(n: i32) {
        unsafe {
            if let Some(_) = &Self::PRIMES {
                return; // Primes already calculated
            }

            let mut primes = Vec::new();
            let mut is_prime = vec![true; (n + 1) as usize];
            is_prime[0] = false;
            is_prime[1] = false;

            let range = (n as f64).sqrt() as i32;

            for i in 2..=range {
                if is_prime[i as usize] {
                    for j in (i * i..=n).step_by(i as usize) {
                        is_prime[j as usize] = false;
                    }
                }
            }

            for i in 2..=n {
                if is_prime[i as usize] {
                    primes.push(i);
                }
            }

            Self::PRIMES = Some(primes);
        }
    }

    // Function to check the prime sub-operation.
    pub fn prime_sub_operation(nums: &[i32]) -> bool {
        if nums.len() <= 1 {
            return true;
        }

        // Getting the primes for reference.
        unsafe {
            if Self::PRIMES.is_none() {
                Self::get_primes(1000);
            }

            let primes = Self::PRIMES.as_ref().unwrap();
            let mut increasing = vec![0; nums.len()];
            increasing[nums.len() - 1] = nums[nums.len() - 1];

            for i in (0..nums.len() - 1).rev() {
                if nums[i] >= increasing[i + 1] {
                    let diff = nums[i] - increasing[i + 1];
                    match primes.binary_search(&diff) {
                        Ok(_) | Err(0) => {
                            return false;
                        }
                        Err(pos) => {
                            let prime = primes[pos];
                            if prime >= nums[i] {
                                return false;
                            }
                            increasing[i] = nums[i] - prime;
                        }
                    }
                } else {
                    increasing[i] = nums[i];
                }
            }

            true
        }
    }
}

fn main() {
    let nums = vec![4, 9, 6, 10];
    let nums2 = vec![5, 7, 11, 13];

    println!("{}", Solution::prime_sub_operation(&nums));
    println!("{}", Solution::prime_sub_operation(&nums2));
}
