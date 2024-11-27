
#include <openssl/evp.h>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string_view>
#include <memory>

bool digest_message(
		const char *message,
		size_t message_len,
		unsigned char **digest,
		unsigned int *digest_len) {

	const auto releaseContext = [](EVP_MD_CTX *const context) {
			if (context == NULL) {
				return;
			}
			EVP_MD_CTX_free(context);
		};

	std::unique_ptr<EVP_MD_CTX, decltype(releaseContext)> context(
		EVP_MD_CTX_new(), releaseContext);
	if (!context) {
		return false;
	}

	if (EVP_DigestInit_ex(&*context, EVP_sha256(), NULL) != 1) {
		return false;
	}

	if (EVP_DigestUpdate(&*context, message, message_len) != 1) {
		return false;
	}

	*digest = static_cast<unsigned char *>(
		OPENSSL_malloc(EVP_MD_size(EVP_sha256())));
	if (digest == NULL) {
		return false;
	}

	if (EVP_DigestFinal_ex(&*context, *digest, digest_len) != 1) {
		return false;
	}
  
  return true;
}

std::string sha256(const std::string_view &str) {
	using namespace std;

	unsigned char *digest = nullptr;
	unsigned int digest_len = 0;
	if (!digest_message(str.data(), str.size(), &digest, &digest_len)) {
		throw std::runtime_error("Filed to digest message");
	}

	stringstream ss;
	for (size_t i = 0; i < digest_len; i++) {
		ss << hex << setw(2) << setfill('0') << (int)digest[i];
	}

	return ss.str();
}

int main() {
    std::cout << sha256("Hello world!") << '\n';
}
