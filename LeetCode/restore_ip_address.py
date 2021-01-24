#!/usr/bin/python

class Solution:
    # @param s, a string
    # @return a list of strings
    def dfs(self, s, k, ip, ans):
      if k >= len(s):
        if len(ip) == 4:
          ip_str = str(ip[0])
          for i in range(1, 4):
            ip_str += '.'
            ip_str += str(ip[i])
          ans.append(ip_str)
        return 
      if len(ip) > 4: return 

      ip_tmp = []
      ip_tmp.extend(ip)
      ip_tmp.append(int(s[k:k+1]))
      self.dfs(s, k+1, ip_tmp, ans)

      if k+2 <= len(s):
        ip_tmp = []
        ip_tmp.extend(ip)
        if s[k] != '0':
          ip_tmp.append(int(s[k:k+2]))
          self.dfs(s, k+2, ip_tmp, ans)

      if k+3 <= len(s):
        ip_tmp = []
        ip_tmp.extend(ip)
        if s[k] != '0' and int(s[k:k+3]) <= 255:
          ip_tmp.append(int(s[k:k+3]))
          self.dfs(s, k+3, ip_tmp, ans)
      
    def restoreIpAddresses(self, s):
      if s == '': return []
      ans = []
      ip = []
      self.dfs(s, 0, ip, ans)
      return ans
