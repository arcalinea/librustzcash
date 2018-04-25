#ifndef LIBRUSTZCASH_INCLUDE_H_
#define LIBRUSTZCASH_INCLUDE_H_

#include <stdint.h>

extern "C" {
    uint64_t librustzcash_xor(uint64_t a, uint64_t b);

    /// Loads the zk-SNARK parameters into memory and saves
    /// paths as necessary. Only called once.
    void librustzcash_init_zksnark_params(
        const char* spend_path,
        const char* output_path,
        const char* sprout_path
    );

    /// Writes the "uncommitted" note value for empty leaves
    /// of the merkle tree. `result` must be a valid pointer
    /// to 32 bytes which will be written.
    void librustzcash_tree_uncommitted(
        unsigned char *result
    );

    /// Computes a merkle tree hash for a given depth.
    /// The `depth` parameter should not be larger than
    /// 62.
    ///
    /// `a` and `b` each must be of length 32, and must each
    /// be scalars of BLS12-381.
    ///
    /// The result of the merkle tree hash is placed in
    /// `result`, which must also be of length 32.
    void librustzcash_merkle_hash(
        size_t depth,
        const unsigned char *a,
        const unsigned char *b,
        unsigned char *result
    );

    /// Validates the provided Equihash solution against
    /// the given parameters, input and nonce.
    bool librustzcash_eh_isvalid(
        uint32_t n,
        uint32_t k,
        const unsigned char* input,
        size_t input_len,
        const unsigned char* nonce,
        size_t nonce_len,
        const unsigned char* soln,
        size_t soln_len
    );
}

#endif // LIBRUSTZCASH_INCLUDE_H_
