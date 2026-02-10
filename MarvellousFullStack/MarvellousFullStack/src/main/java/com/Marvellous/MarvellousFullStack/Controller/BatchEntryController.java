package com.Marvellous.MarvellousFullStack.Controller;


import com.Marvellous.MarvellousFullStack.Entity.BatchEntry;
import com.Marvellous.MarvellousFullStack.Service.BatchEntryService;
import org.bson.types.ObjectId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping({"/batches"})
public class BatchEntryController
{
    @Autowired
    private BatchEntryService batchEntryService;

    @GetMapping
    public ResponseEntity<?> getAll() {
        List<BatchEntry> alldata = this.batchEntryService.getAll();
        return alldata != null && !alldata.isEmpty() ? new ResponseEntity<>(alldata, HttpStatus.OK) : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @PostMapping
    public ResponseEntity<BatchEntry> createEntry(@RequestBody BatchEntry myentry) {
        try {
            this.batchEntryService.saveEntry(myentry);
            return new ResponseEntity(myentry, HttpStatus.CREATED);
        } catch (Exception var3) {
            return new ResponseEntity(HttpStatus.BAD_REQUEST);
        }
    }

    @DeleteMapping({"/id/{myid}"})
    public ResponseEntity<?> deleteEntryById(@PathVariable ObjectId myid) {
        this.batchEntryService.deleteById(myid);
        return new ResponseEntity(HttpStatus.NO_CONTENT);
    }

    @PutMapping({"/id/{myid}"})
    public ResponseEntity<?> updateEntryById(@PathVariable ObjectId myid, @RequestBody BatchEntry myentry) {
        BatchEntry old = (BatchEntry)this.batchEntryService.findById(myid).orElse((BatchEntry) null);
        if (old != null) {
            old.setName(myentry.getName());
            old.setFees(myentry.getFees());
            this.batchEntryService.saveEntry(old);
            return new ResponseEntity(old, HttpStatus.OK);
        } else {
            return new ResponseEntity(HttpStatus.NOT_FOUND);
        }
    }
}
