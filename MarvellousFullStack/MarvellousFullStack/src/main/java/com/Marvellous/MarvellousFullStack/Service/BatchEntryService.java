package com.Marvellous.MarvellousFullStack.Service;

import com.Marvellous.MarvellousFullStack.Entity.BatchEntry;
import com.Marvellous.MarvellousFullStack.Repository.BatchEntryRepository;
import org.bson.types.ObjectId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Optional;

@Component
public class BatchEntryService
{
    @Autowired
    private BatchEntryRepository batchEntryRepository;

    public void saveEntry(BatchEntry batchEntry)
    {
        this.batchEntryRepository.save(batchEntry);
    }

    public List<BatchEntry> getAll()
    {
        return this.batchEntryRepository.findAll();
    }

    public Optional<BatchEntry> findById(ObjectId id)
    {
        return this.batchEntryRepository.findById(id);
    }

    public void deleteById(ObjectId id)
    {
        this.batchEntryRepository.deleteById(id);
    }
}
