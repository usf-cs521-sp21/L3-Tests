source "${TEST_DIR}/lib/funcs.bash"

test_start "Finding households with more than 7 children"

program_output=$(./query 'NOC > 7' < "${TEST_DIR}/inputs/psam_h11.csv")

compare <(cat "${TEST_DIR}/inputs/05.expected") <(echo "${program_output}")

test_end
