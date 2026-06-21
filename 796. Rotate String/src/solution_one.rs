pub struct Solution {}

impl Solution {
    pub fn rotate_string(s: String, goal: String) -> bool {
        if s.len() == goal.len() {
            let given_string = s.bytes().collect::<Vec<u8>>();
            let goal_string = goal.bytes().collect::<Vec<u8>>();

            let mut given_str_pointer: usize;
            let mut goal_str_pointer: usize = 0;
            let mut given_str_pointer_occurances: Vec<usize> = Vec::new();

            for i in 0..given_string.len() {
                if &given_string[i] == goal_string.first().unwrap() {
                    given_str_pointer_occurances.push(i);
                }
            }

            for i in 0..given_str_pointer_occurances.len() {
                given_str_pointer = given_str_pointer_occurances[i];

                while goal_str_pointer < goal.len() {
                    if goal_string[goal_str_pointer] != given_string[given_str_pointer] {
                        break;
                    }
                    given_str_pointer = (given_str_pointer + 1) % given_string.len();
                    goal_str_pointer += 1;
                }

                if goal_str_pointer == goal.len() {
                    return true;
                }

                goal_str_pointer = 0;
            }

            false
        } else {
            false
        }
    }
}
