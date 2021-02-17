source "${TEST_DIR}/lib/funcs.bash"

test_start "Households with 5 cars but less than 3 rooms"

program_output=$(\
    ./query 'VEH=5' < "${TEST_DIR}/inputs/psam_h46.csv" | \
    ./query ' RMSP<      3 ' \
)

compare <(cat "${TEST_DIR}/inputs/06.expected") <(echo "${program_output}")

test_end
