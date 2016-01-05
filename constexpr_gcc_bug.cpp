// Minimum reproduction of the gcc constexpr bug I reported, see https://gcc.gnu.org/bugzilla/show_bug.cgi?id=67824
static constexpr const char root[] = "12";
static constexpr const char* root2 = "12";

int main()
{
    static_assert(root < root + 1, "This works");
    static_assert(root2 < root2 + 1, "This fails");
}
