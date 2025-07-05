def search_key(self, key):
        node = self._search_node(self.root, key)
        return node.key if node else None