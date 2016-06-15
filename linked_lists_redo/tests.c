void run_all_tests() {
  test_size();
  test_push_front();
  test_empty();
  test_value_at();
  test_pop_front();
  test_push_back();
  test_pop_back();
  test_front();
  test_back();
//  test_insert();
//  test_erase();
//  test_value_n_from_end();
//  test_reverse();
//  test_reverse_single();
//  test_reverse_empty();
//  test_remove();
}

void test_size() {
  node_t *head = NULL;

  assert(size(head) == 0);

  node_t *first = malloc(sizeof(node_t));
  check_address(first);

  first->val = 1;
  first->next = NULL;

  head = first;

  assert(size(head) == 1);

  destroy_list(head);
}

void test_push_front() {
  node_t *head = NULL;

  push_front(&head, 5);

  assert(size(head) == 1);

  push_front(&head, 8);
  push_front(&head, 12);

  assert(size(head) == 3);

  destroy_list(head);
}

void test_empty() {
  node_t *head = NULL;

  assert(empty(head));

  destroy_list(head);
}

void test_value_at() {
  node_t *head = NULL;

  push_front(&head, 7);
  assert(value_at(head, 0) == 7);

  destroy_list(head);
}

void test_pop_front() {
  node_t *head = NULL;

  push_front(&head, 9);
  push_front(&head, 25);
  assert(pop_front(&head) == 25);
  assert(pop_front(&head) == 9);

  destroy_list(head);
}

void test_push_back() {
  node_t *head = NULL;

  push_back(&head, 99);
  assert(value_at(head, 0) == 99);

  push_back(&head, 88);
  assert(value_at(head, 1) == 88);

  destroy_list(head);
}

void test_pop_back() {
  node_t *head = NULL;

  push_back(&head, 122);
  assert(pop_back(&head) == 122);

  push_back(&head, 564);
  push_back(&head, 72);
  assert(pop_back(&head) == 72);
  assert(pop_back(&head) == 564);

  assert(size(head) == 0);

  destroy_list(head);
}

void test_front() {
  node_t *head = NULL;

  push_front(&head, 7);
  assert(front(head) == 7);

  push_front(&head, 6);
  assert(front(head) == 6);

  destroy_list(head);
}

void test_back() {
  node_t *head = NULL;

  push_back(&head, 77);
  assert(back(head) == 77);

  push_back(&head, 42);
  assert(back(head) == 42);

  pop_back(&head);
  assert(back(head) == 77);

  destroy_list(head);
}