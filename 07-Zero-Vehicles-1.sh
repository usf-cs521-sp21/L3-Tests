source "${TEST_DIR}/lib/funcs.bash"

test_start "Number of South Dakota households with zero cars (includes header)"

program_output=$(\
    ./query 'VEH=0' < "${TEST_DIR}/inputs/psam_h46.csv" | \
    wc -l
)

compare <(echo "771") <(echo "${program_output}")

test_end
