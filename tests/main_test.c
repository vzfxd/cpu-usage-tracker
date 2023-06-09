extern void test_queue_main(void);
extern void test_reader_main(void);
extern void test_analyzer_main(void);

int main(void)
{
    test_queue_main();
    test_reader_main();
    test_analyzer_main();
}